N, M = map(int, input().split())
connected = []
remain = []
for n in range(N):
    connected.append([])
    remain.append(n)
for _ in range(M):
    a, b = map(int, input().split())
    connected[a-1].append(b-1)
    connected[b-1].append(a-1)
    

ans = 0
node = 0
remain.remove(0)

def find_next_node(remain_arr, current_node):
    global ans
    if remain_arr == []:
        ans += 1
        return
    for next_node in connected[current_node]:
        if next_node in remain_arr:
            find_next_node([i for i in remain_arr if i != next_node], next_node)

find_next_node(remain, 0) 
print(ans)