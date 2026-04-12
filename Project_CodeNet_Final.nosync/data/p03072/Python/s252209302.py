n = int(input())
h = [int(x) for x in input().split()]

print(len([1 for i in range(n) if h[i] >= max(h[:i+1])]))
