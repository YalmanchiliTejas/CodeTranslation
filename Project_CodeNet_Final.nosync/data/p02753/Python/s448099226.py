li = list(str(input()))
judge = True
for i in range(len(li)-1):
    if li[i] != li[i+1]:
        judge = False
if judge == True:
    print('No')
else:
    print('Yes')