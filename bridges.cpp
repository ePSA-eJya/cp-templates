int timer=1;
void dfs(int node,int parent,vector<vector<int>>&adj,vector<vector<int>>&b,vector<int>&vis,vector<int>&low,vector<int>&tin){
    vis[node]=1;
    low[node]=timer;
    tin[node]=timer;
    timer++;

    for(auto it:adj[node]){
        if(it==parent) continue;
        if(vis[it]==0){
            dfs(it,node,adj,b,vis,low,tin);
            low[node]=min(low[it],low[node]);
            if(low[it]>tin[node]){
                b.push_back({it,node});
            }
        }
        else low[node]=min(low[it],low[node]);
    }

}
vector<vector<int>> bridges(int n, vector<vector<int>>& conn) {
    vector<vector<int>>adj(n+1);
    for(auto it:conn){
        int u=it[0],v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>vis(n,0);
    vector<int>low(n,0);
    vector<int>tin(n,0);
    vector<vector<int>>b;
    dfs(0,-1,adj,b,vis,low,tin);
    return b;        
}
