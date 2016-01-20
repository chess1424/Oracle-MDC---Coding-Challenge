#include <bits/stdc++.h>
 
using namespace std;
 
int countID = 0;
vector<int> memorization;
 
typedef struct node{
    string str;
    int id;
    int maxSize;
    int maxIndex;
    bool visited;
    vector< pair< string , int > > last; 
    vector< string > first; 
    vector< pair < node* , int > > next;
}node;
 
// Funcion to find solution using recursion and memorization.
int compute(node** currNode)
{
    if(memorization[(*currNode) -> id] != -1) // This node was already calculated.
        return memorization[(*currNode) -> id];

    if((*currNode)->next.size() == 0) // No more nodes contected to currNode
        return (*currNode)->str.length();
    
    if((*currNode)->visited == true) // this node was already visited
        return memorization[(*currNode)->id] = 0;
 
    (*currNode)->visited = true;
 
    for(int i = 0; i < (*currNode)->next.size(); i++)
    {
        int var;
        var = compute(&(*currNode)->next[i].first) + (*currNode)->next[i].second;
        
        if(var > (*currNode)->maxSize)
        {
            (*currNode)->maxSize = var;
            (*currNode)->maxIndex = i;
        }
    }
 
    (*currNode)->visited = false;
    return memorization[(*currNode)->id] = (*currNode)->maxSize;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string str;
    map< string, vector< node* > > begin;
    map< string, vector< pair < node* , int > > > end;
 
    // Creating root node
    node* root = new node;
    root->str = "";
    root->maxSize = 0;
    root->maxIndex = 0;
    root->visited = false;
 
    while(getline(cin, str))
    {
        // Creating new node.
        node* newNode = new node;
        newNode->id = countID++;
        newNode->str = str;
        newNode->maxIndex = 0;
        newNode->maxSize = 0;
        newNode->visited = false;
 
        newNode->last.push_back( make_pair(str , 0) ); 
        string aux = "";

        for(int i = 0; i < str.length() ; i++)
        {
            if(str[i] == ' ') 
                newNode->last.push_back( make_pair( str.substr(i + 1) , i + 1) );
                
            aux += str[i];
            newNode->first.push_back(aux);
        }
 
        // Building graph

        // Finding and connecting newNode to others nodes.
        bool conected = false;
        for(int i = 0; i < newNode->first.size(); i++)
            if(end[ newNode->first[i] ].size() > 0)
            {
                for(int j = 0; j < end[ newNode->first[i] ].size(); j++)
                    end[ newNode->first[i] ][j].first->next.push_back( make_pair( newNode , end[ newNode->first[i] ][j].second ) );
                conected = true;
            }   
        
 
        // If I didn't find nodes to connect newNode. Connect new Node to root.
        if(!conected)
            root->next.push_back( make_pair(newNode , 0) );

        // Finding and connecting newNode to others nodes.
        for(int i = newNode->last.size()-1; i >= 0; i--)
            if(begin[ newNode->last[i].first ].size() > 0)
                for(int j = 0; j < begin[ newNode->last[i].first ].size(); j++)
                    newNode->next.push_back( make_pair( begin[ newNode->last[i].first ][j] , newNode->last[i].second ) );
        
        // Storing all iformation of newNode
        for(int i = 0; i < newNode->last.size(); i++)
            end[ newNode->last[i].first ].push_back( make_pair( newNode , newNode->last[i].second ) );
        
        for(int i = 0; i < newNode->first.size(); i++)
            begin[ newNode->first[i] ].push_back(newNode);
        
 
 
    }
    memorization = vector<int>(countID , -1); 
    compute(&root);


    // Printing the solution.

    node* aux = root;
    string out = "";
    while(aux->next.size() > 0)
    {
        if(aux->next[aux->maxIndex].first->visited == true) break;
        
        out += aux->str.substr(0, aux->next[aux->maxIndex].second);
        aux->visited = true;
        aux = aux->next[aux->maxIndex].first;
    }
    out += aux->str;
    cout<<out<<'\n';
    
    return 0;
}