X,Y,Z=map(int, input().split())
count=0
while Y*(count+1)+Z*(count+2)<=X:
  count+=1
print(count)