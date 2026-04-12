now=input()

while now!="#":
    order_raw = input()
    order = [int(s)-1 for s in order_raw.split(' ')]

    box = [[]]
    for n in now:
        if n=='/':
            box.append([])
        elif n=='b':
            box[-1].append('b')
        else:
            for _ in range(int(n)):
                box[-1].append('.')

    box[order[0]][order[1]] = '.'
    box[order[2]][order[3]] = 'b'

    res=""
    index=0
    for bo in box:
        for b in bo:
            if b=='b':
                if index>0:
                    res+=str(index)
                    index=0
                res+="b"
            else:
                index+=1
        if index>0:
            res+=str(index)
            index=0
        res+="/"

    print(res[:-1])

    now=input()

            
        
        

