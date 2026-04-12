n=int(raw_input())
s=raw_input()
k=int(raw_input())

c=s[k-1]
ret = ""
for i in s:
    if i!=c:
        ret+="*"
    else:
        ret+=c
print(ret)
