import math
while True:
    n = int(input())
    if n == 0:
        break
    s=[]
    for i in range(0,n):
        s.append(int(input()))
    s.remove(min(s))
    s.remove(max(s))
    print(math.floor(sum(s)/len(s)))
