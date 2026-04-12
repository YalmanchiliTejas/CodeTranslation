n = int(input())
h = list(map(int, input().split()))
print(sum(1 for i in range(n) if h[i] >= max(h[0:i+1])))
