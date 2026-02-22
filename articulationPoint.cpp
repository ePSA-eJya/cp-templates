int timer=1;
void dfs(int node,int parent,vector<int>adj[],vector<int>&tin,vector<int>&vis,vector<int>&low,vector<int>&mark){
    vis[node]=1;
    low[node]=timer;
    tin[node]=timer;
    timer++;
    int child=0;
    for(auto it:adj[node]){
        if(it==parent) continue;
        
        if(!vis[it]){
            dfs(it,node,adj,tin,vis,low,mark);
            low[node]=min(low[node],low[it]);
            
            if(low[it]>=tin[node] && parent!=-1){
                // ans.push_back(node);
                mark[node]=1;
            }
            child++;
        }
        else low[node]=min(low[node],tin[it]);
    }
    
    if(parent==-1 &&child>1) mark[node]=1;
    
}
vector<int> articulationPoints(int n, vector<int> adj[]) {
    // Code here
    vector<int>tin(n,0);
    vector<int>low(n,0);
    vector<int>vis(n,0);
    vector<int>mark(n,0);
    vector<int>ans;
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,adj,tin,vis,low,mark);
        }
    }

    for(int i=0;i<n;i++){
        if(mark[i]) ans.push_back(i);
    }
    if(ans.size()==0) return {-1};
    return ans;
    
}
