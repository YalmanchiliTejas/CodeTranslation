R,G,B=map(str,input().split())
ans="NO"
num=int(R+G+B)
if num%4==0:
    ans="YES"
print(ans)