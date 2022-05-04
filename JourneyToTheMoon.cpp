//https://www.hackerrank.com/challenges/journey-to-the-moon/problem?isFullScreen=true
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    bool visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    queue<int> vert;
    int next = 0;
    long k = n;
    long long pairCount = k * (k - 1) / 2;
    cout << pairCount << endl;
    int count = 0;
    vector<int> adj[n];
    vector<int> countries;
    for(int i = 0; i < astronaut.size(); i++){
        adj[astronaut[i][0]].push_back(astronaut[i][1]);
        adj[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    while (count < n) {
        while (next < n && visited[next]) {
            next++;
        }
        vert.push(next);
        visited[next] = true;
        count++;
        int a = 1;
        while(!vert.empty()){
            int v = vert.front();
            vert.pop();
            for(int i = 0; i < adj[v].size(); i++){
                if(!visited[adj[v][i]]){
                    visited[adj[v][i]] = true;
                    vert.push(adj[v][i]);
                    count++;
                    a++;
                }
            }
        }
        if(a != 1){
            pairCount -= a * (a - 1) / 2;
        }
        if(count > 99995){
            cout << pairCount << endl;
        }
    }
    return pairCount;
}
