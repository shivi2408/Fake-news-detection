#include <bits/stdc++.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

void dfs(vector<vector<int>> &G,int src,char prop,vector<int> &vis,vector<char> &propv){
    if(vis[src]==true)
    return;
    
    vis[src]=true;
    cout<<"Current value at "<<src<<" is "<<prop<<endl;
    propv[src]=prop;
    
    
    for(int i=0;i<G[src].size();i++){
        dfs(G,G[src][i],prop,vis,propv);
    }
}


int main()
{
    cout<<"Hey, please enter number of nodes:"<<endl;
    int n;cin>>n;
    cout<<"Please enter number of edges:"<<endl;
    int e;cin>>e;
    cout<<"Generating random "<<e<<" edges for nodes 1 to "<<n<<"..."<<endl;
    sleep(3);
    
    
    //generating graph
    vector<vector<int>> G(n+1);
    vector<char> propv(n+1,'*');
    
    for(int i=1;i<=e;i++){
        int a=(rand()%n)+1;
        int b=(rand()%n)+1;
        cout<<i<<" edge: "<<a<<" "<<b<<endl;
        G[a].push_back(b);
        G[b].push_back(a);
        sleep(1);
    }
    
    //user choice for source
    while(1){
    cout<<"\n\n--------------------------------------"<<endl;
    cout<<"Hey, please enter the souce node from where to propagate:"<<endl;
    int src;cin>>src;
    
    cout<<"please enter a character for the propagation :"<<endl;
    char prop;cin>>prop;
    
    if(src>n){
        cout<<"Error: Ohoooooooooo, U've entered wrong nodes. Please enter another one: "<<endl;
    }
    //propagation
    else{
        cout<<"\nThese are the all nodes which can be propagated by entered source node "<<src<<" :"<<endl;
        vector<int> vis(n+1,false);
        dfs(G,src,prop,vis,propv);
        cout<<"\nWe can reach total "<<G[src].size()<<" nodes from given node "<<src<<endl;
    }
    
        sleep(2);
    }
    
    return 0;
}

