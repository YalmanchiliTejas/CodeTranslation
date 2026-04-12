n=input()
m=input()
l=int(input())
kotae=""
key=m[l-1]

for i in range(len(m)):
    if m[i] != key:
        kotae=kotae+"*"
    else:
        kotae=kotae+key
print(kotae)     