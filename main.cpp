class Solution
        {
        public:
            //Function to find sum of weights of edges of the Minimum Spanning Tree.
            int spanningTree(int V, vector<vector<int>> adj[])
            {

                // for(int i = 0 ; i<V ; i++){
                //     for (auto x : adj[i]){
                //         cout<<i<<"--->";
                //         cout<<x[0]<<" "<<x[1];
                //     }
                //     cout<<"\n";
                // }

                vector<int> key(V , INT_MAX);
                vector<bool> mst(V , false);  /// used for storing the mst set ///
                vector<int> parent(V , -1);  /// used for storing the cycle ///

                priority_queue<pair<int, int> , vector<pair<int , int>> , greater<pair<int, int>>>pq;
                key[0] = 0;
                int ans = 0;

                // index --> and its corresponding value ///
                pq.push({0 , 0});   // weight , node ///

                while (!pq.empty()){

                    int u = pq.top().second;
                    pq.pop();
                    mst[u] = true;

                    for (auto x : adj[u]){

                        int v = x[0];
                        int weight = x[1];

                        if (mst[v] == false && key[v] > weight){
                            parent[v] = u;
                            key[v] = weight;
                            pq.push({key[v] , v});
                        }
                    }
                }
                for (auto x : key){
                    ans += x;
                }

                return ans;

            }
        };
 