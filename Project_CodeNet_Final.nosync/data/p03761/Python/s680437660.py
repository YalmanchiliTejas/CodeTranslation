n = int(input())
lst = [None for i in range(n)]
for i in range(n):
    lst[i] = input()

def f(s):
    dic = {}
    for i in s:
        if i in dic:
            dic[i]+=1
        else:
            dic[i]=1
    return dic

dic1 = f(lst[0])
for i in range(1,n):
    dic2 = f(lst[i])
    for i in dic1:
        if i in dic2:
            dic1[i] = min(dic1[i],dic2[i])
        else:
            dic1[i] = 0

ans = ""
for i in dic1:
    ans += i*dic1[i]

ans = sorted(ans)
print("".join(ans))
