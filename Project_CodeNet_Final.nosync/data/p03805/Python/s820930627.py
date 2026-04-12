
N,M = [int(i) for i in input().split(" ")]
neighbor_dict={n:set() for n in range(1,N+1)}


for i in range(M):
    a,b = [int(i) for i in input().split(" ")]
    neighbor_dict[a].add(b)
    neighbor_dict[b].add(a)

ans = 0

def crawl(vertex:int,visited_set:set):
    visited_set = visited_set | {vertex}
    if len(visited_set) == N:
        global ans
        ans = ans + 1
        return

    to_visit = set(neighbor_dict[vertex]) - visited_set

    for v in to_visit:
        crawl(v,visited_set)

crawl(1,set())
print(ans)