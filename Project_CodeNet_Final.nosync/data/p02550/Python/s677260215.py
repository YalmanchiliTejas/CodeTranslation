n, x, m = map(int, input().split())
count=x
now=x
flag=-1
sled=[now]
for i in range(1,n):
     now=(now*now)%m
     if now==0:
         flag=0
         break
     if now in sled:
         start=sled.index(now)
         nokori=n-i
         flag=2
         break
     
     else:
         sled.append(now)
     count+=now
     #print(i,now,count)

if flag==2:
    #print(count)
    sled=sled[start:]
    roopnum=int(nokori/len(sled))
    amari=nokori%len(sled)
    
    one_roop=sum(sled)
    count+=one_roop*roopnum
    #print(count)
    for i in range(amari):
        count+=sled[i]
print(count)