str=input();
mountains=input().split(" ");
higher=0;
num=0;
for mountain in mountains:
  if higher<=int(mountain):
    num+=1;
    higher=int(mountain);

print(num);