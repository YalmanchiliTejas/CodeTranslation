def eee(s,k):
    a = s[k-1]
    k = list(filter(lambda x:x!=a,s))
    z = ''.join(s)
    for i in k:
        z = z.replace(i,'*')
    return z

n = int(input())
s = list(input())
k = int(input())
print(eee(s,k))