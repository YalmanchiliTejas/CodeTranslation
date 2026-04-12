n = int(input())
h = list(map(int,input().split()))
print(len([h[i] for i in range(n) if h[i] >= max(h[:i+1])]))