N = input()
lst = list(map(int, input().split()))
a = lst[0]
ret = 1
for x in lst[1:]:
    if a <= x:
        ret+=1
    a = max(a, x)
print(ret)