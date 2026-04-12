kazu = int(input())#文字数
mozi = input()#文字
sitei = int(input())#取り出す文字
lst = []
#print(mozi[sitei])
for i in range(kazu):
    if mozi[i] == mozi[sitei-1]:
        print(mozi[i],end ="")
    else:
        print("*",end="")