def B(lst,r=[],c=1):
    if len(lst) == c:
        return r
    if len([i for i in lst[0:c] if lst[c] >= i]) == c:
        return B(lst,r + [lst[c]],c+1)
    else:
        return B(lst,r,c+1)

i = int(input())
lst = list(map(int,input().split(" ")))
print(len(B(lst))+1)