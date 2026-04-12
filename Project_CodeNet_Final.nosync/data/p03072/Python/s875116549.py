n = int(input())
a = list(map(int, input().split()))
print(sum(max([0] + a[:i]) <= a[i] for i in range(n)))