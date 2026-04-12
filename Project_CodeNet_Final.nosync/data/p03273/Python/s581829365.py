def str_del(string,index):
    string = string[:index]+string[index+1:]
    return string




H,W=map(int,input().split())
lines=[]
for i in range(H):
    get=input()
    flag=True
    for s in get:
        if s=='#':
            flag=False
            break
    if not flag:
        lines.append(get)
    else:
        H-=1


i=0
while(i<W):
    same_flag = True

    for s in range(len(lines)):
        #print(lines)
        if(lines[s][i]=='#'):
                same_flag=False
                break


    if same_flag:
        for s in range(len(lines)):
            lines[s]=str_del(lines[s],i)

        i-=1
        W-=1
            #print(lines[s])
        #print('deleted')

    i+=1


for i in range(len(lines)):
    print(lines[i])

