n = int(input())
h = list(map(int, input().split()))
ans = sum(h[i] == max(h[:i+1]) for i in range(n))
print(ans)