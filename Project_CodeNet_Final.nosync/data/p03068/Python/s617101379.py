x = int(input());
li = list(input());
y = int(input());

for i in range(len(li)):
    if str(li[i]) != str(li[y-1]):
        li[i] = '*';
for i in range(len(li)):
      print(li[i], end="");

print();