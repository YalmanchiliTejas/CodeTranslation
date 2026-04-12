n=int(input())
hoge=input()
k=int(input())

huga=hoge[k-1]

for i in range(n):
  if(hoge[i]==huga):
    print(huga,end="")
  else:
    print("*",end="")
    
print("")