
#グラフの初期化
import itertools

n, m = map(int, input().rstrip().split())
mylist = [[0 for j in range(n)] for i in range(n)]

for i in range(m):
    a, b = map(int, input().rstrip().split())
    mylist[a-1][b-1] = 1

vist = [i for i in range(1, n)]

result = 0
for v in itertools.permutations(vist):
    index = 0
    mylist2 = mylist[:]
    past = 0
    for i in v:
        a = min(past, i)
        b = max(past, i)
        if mylist2[a][b] != 1:               
            break
        past = i
        index += 1
    if index == n-1:
        result += 1
        
print(result)