r = list("yuiophjklnm")
while True:
    a = list(input())
    if a == ["#"]:
        break
    ans = 0
    for i in range(len(a)-1):
        if (a[i] in r) != (a[i+1] in r):
            ans += 1
    print(ans)
        
