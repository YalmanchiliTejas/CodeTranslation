import itertools

n,m = map(int,input().split())

a = [list(sorted(map(int, input().split()))) for i in range(m)]
a.sort()

cnt = 0

for i in itertools.permutations(range(2, n +1), (n-1)):
    li = [1] + list(i)
    if sum(list(sorted(edge)) in a for edge in zip(li, li[1:])) == n-1:
        cnt += 1
    
print(cnt)
    