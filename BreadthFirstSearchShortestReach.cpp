//https://www.hackerrank.com/challenges/bfsshortreach/problem?isFullScreen=true
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> dist;
    for(int i = 0; i < n; i++){
        dist.push_back(INT_MAX);
    }
    queue<int> v;
    vector<int> adj[n];
    for(int i = 0; i < m; i++){
        adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
        adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
    }
    dist[s - 1] = 0;
    v.push(s - 1);
    while(!v.empty()){
        int a = v.front();
        v.pop();
        for(int i = 0; i < adj[a].size(); i++){
            if(dist[a] + 6 < dist[adj[a][i]]){
                dist[adj[a][i]] = dist[a] + 6;
                v.push(adj[a][i]);
            }
        }
    }
    vector<int> result;
    for(int i = 0; i < n; i++){
        if(dist[i] == INT_MAX){
            result.push_back(-1);
        }
        else if(i != s - 1){
            result.push_back(dist[i]);
        }
    }
    return result;
}