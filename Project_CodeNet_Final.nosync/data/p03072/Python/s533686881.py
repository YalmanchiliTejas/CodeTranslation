n = int(input())
h = [int(_) for _ in input().split(' ')]
print(len([i for i in range(n) if h[i] >= max(h[:i+1])]))
