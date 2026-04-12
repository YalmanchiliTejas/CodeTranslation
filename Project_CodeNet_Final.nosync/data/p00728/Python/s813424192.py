def score(li):
    li.remove(max(li))
    li.remove(min(li))
    return int(sum(li) / (len(li)))

while 1:
    n = int(input())
    if n == 0: # ???????????¶
        break
    s = [int(input()) for i in range(n)]
    print(score(s))