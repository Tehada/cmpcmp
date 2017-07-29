std::vector<std::vector<int>> adjList;
int V = adjList.size(); // number of vertices

int deg(int vertex) {
    int ans = 0;
    for (int i = 0; i < V; ++i)
        if (adjList[vertex][i]) ++ans;
    return ans;
}

//takes constant time if we use adjList
bool check_if_in_clique(int vertex) { 
    for (int i = 0; i < V; ++i) {
        if (adjList[vertex][i]) {
            for (int j = i; j < V; ++j)
                if (adjList[i][j] && adjList[vertex][j]) return true;
        }
    }
    return false;
}

int main() {
    bool ans = false;
    for (int vertex = 0; vertex < V; ++vertex) {
        if (deg(vertex) > 1 && check_if_in_clique(vertex)) {
            ans = true;
            break;
    }
    if (ans) std::cout << "YES\n";
    else std::cout << "NO\n";
}

//O(V) * [O(V) + O(V^2)] == O(V^3) adjList
//O(V) * C == O(V) adjList
