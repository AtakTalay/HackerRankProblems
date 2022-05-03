//https://www.hackerrank.com/challenges/primsmstsub/problem?isFullScreen=true
int minEdge(int key[], bool visited[], int n){
    int min = INT_MAX;
    int minIndex = -1;
    for(int i = 0; i < n; i++){
        if(visited[i] == false && key[i] < min){
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}


int prims(int n, vector<vector<int>> edges, int start) {
    int total = 0;
    bool visited[n];
    int key[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
        key[i] = INT_MAX;
    }
    key[start - 1] = 0;
    for(int i = 0; i < n; i++){
        int u = minEdge(key, visited, n);
        visited[u] = true;
        for(int j = 0; j < edges.size(); j++){
            if(edges[j][0] - 1 == u){
                if(!visited[edges[j][1] - 1] && edges[j][2] < key[edges[j][1]- 1]){
                    key[edges[j][1] - 1] = edges[j][2];
                }
            }
            else if(edges[j][1] - 1 == u){
                if(!visited[edges[j][0] - 1] && edges[j][2] < key[edges[j][0] - 1]){
                    key[edges[j][0] - 1] = edges[j][2];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << key[i] << endl;
        total += key[i];
    }
    return total;
}