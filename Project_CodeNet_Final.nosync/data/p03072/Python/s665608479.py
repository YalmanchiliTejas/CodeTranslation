n=int(input())
h=[int(i) for i in input().split()]
print(sum(max(h[:i+1])<=h[i] for i in range(n)))