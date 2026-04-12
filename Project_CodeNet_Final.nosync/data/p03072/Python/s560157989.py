n = int(input())
*h, = map(int, input().split())
ans = sum([1 if h[i]==max(h[:i+1]) else 0 for i in range(n)])
print(ans)