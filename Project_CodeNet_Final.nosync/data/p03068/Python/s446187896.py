n = input() # len
s = input() # str
k = input() # index

tmp = s[int(k)-1]
ret = ""
for i in range(int(n)):
    if not s[i] == tmp:
        ret+='*'
    else:
        ret+=s[i]

print(ret)