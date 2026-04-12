N, X, M = map(int, input().split())

A = X
ans = A

visited = [0]*M
tmp = []

i = 2
while i <= N:
    A = (A*A) % M
    if visited[A] == 0:
        visited[A] = i
        tmp.append(A)
        ans += A
    else:
        ans += A
        loop_length = i-visited[A]
        loop_val = tmp[-1*loop_length:]
        loop_count = (N-i) // loop_length
        ans += sum(loop_val) * loop_count
        visited = [0]*M
        i += loop_length * loop_count

    i += 1

print(ans)
