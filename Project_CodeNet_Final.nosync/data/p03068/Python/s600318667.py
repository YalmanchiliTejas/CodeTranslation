n=int(raw_input())
s=raw_input().rstrip()
k=int(raw_input())
c=s[k-1]
print ''.join([c if s[i]==c else '*' for i in range(n)])