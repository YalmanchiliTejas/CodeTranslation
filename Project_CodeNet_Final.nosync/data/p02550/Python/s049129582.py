N,X,M = map(int,input().split())

ans = 0

dic = {}

roopCounter = 0
tmp = X
dic[tmp]=0
consump=0

while True:
    ans += tmp
    tmp = pow(tmp,2,M)
    roopCounter += 1
    if tmp in dic:
        consump = roopCounter
        roopCounter = roopCounter-dic[tmp]
        rooper = tmp
        break
    else:
        dic[tmp]=roopCounter

new_dic = {}
tmp = rooper
new_dic[tmp]=0
while True:
    tmp = pow(tmp,2,M)
    if tmp in new_dic:
        break
    else:
        new_dic[tmp]=0
once = 0
for i in new_dic:
    once+=i

ans += once*((N-consump)//roopCounter)

tmp = rooper
for i in range(0,(N-consump)%roopCounter):
    ans += tmp
    tmp = pow(tmp,2,M)

print(ans)