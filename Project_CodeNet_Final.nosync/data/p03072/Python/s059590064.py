def mountain(s):
    k = 1
    c = s[0]
    for i in range(len(s)-1):
        if s[i+1]>=c:
            c = s[i+1]
            k = k+1
    return k
a=input()
s=list(map(int, input().split()))
print(mountain(s))