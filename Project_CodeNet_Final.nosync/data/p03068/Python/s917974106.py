n,s,k=open(0).read().split();k=int(k)-1;
print("".join([("*" if x!=s[k] else x) for x in s]))