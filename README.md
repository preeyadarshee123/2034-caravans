# 2034-caravans
Timus 2034 Caravans Editorial :

Let s=Start point , f=finish point , r= point at which robber is staying
Now there can be multiple shortest paths from s to f
We will try to find every node which is on the shortest paths from s to f
It can be done by doing two breadth first search and calculating node's distance from their respective sources.
1. Start point.
2. Finish point.
Next step would be doing breadth first seach from r and storing distance of every node from it to some array.
Now since we need to calculate maximum of minimum of every shortest path .
We will do it in the following way.
We will initialize a vector of size length of shortest path with -1.
We will assume vector's indices as distance from the start point in the shortest path .
Then the next step is to check which vertices are on the shortest paths.
We can check if any vertex is on the shortest path by checking the following condition:
(distance of node from start point) + (distance of node from finish point) == (length of shortest path).
If this condition is true :
Then we got a node which is in the shortest path .
in the vector for that specific distance we will do the following :
if the  current value in the vector at index [it's distance from start point] is less than the node's distance from the robber point , we will update the value with the new value(node's distance from the robber point).
at the end we will have a path whose nodes are such that their distance from robbers point is maximum
now we will take the minimum value from the vector.
that is the answer :D
