N, X, M = map(int, input().split())
 
def next_f(a):
    return a * a % M
 
visited = [None] * M
sum_at_visit = [None] * M
loop_done = False
 
time = 1
ans = 0
x = X
while time <= N:
    if not loop_done and visited[x] is not None:
        # found cycle                                                                                                                                         
        loop_len = time - visited[x]
        loop_sum = ans + x - sum_at_visit[x]
        loops = (N-loop_len-time) // loop_len
        time += loop_len * loops
        ans += loop_sum * loops
        loop_done = True
    ans += x
    visited[x] = time
    sum_at_visit[x] = ans
    time += 1
    x = next_f(x)
print(ans)