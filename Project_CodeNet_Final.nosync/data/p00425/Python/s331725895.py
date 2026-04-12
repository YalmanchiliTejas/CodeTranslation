a,b,c,d,e,f = 1,2,3,4,5,6

def North():
    global a,b,c,d,e,f
    a,b,c,d,e,f =b,f,c,d,a,e
def South():
    global a,b,c,d,e,f
    a,b,c,d,e,f =e,a,c,d,f,b
def East():
    global a,b,c,d,e,f
    a,b,c,d,e,f =d,b,a,f,e,c
def West():
    global a,b,c,d,e,f
    a,b,c,d,e,f =c,b,f,a,e,d
def Right():
    global a,b,c,d,e,f
    a,b,c,d,e,f =a,c,e,b,d,f
def Left():
    global a,b,c,d,e,f
    a,b,c,d,e,f =a,d,b,e,c,f


x = int(raw_input())
while x > 0:
    y = range(x)
    z =1
    a,b,c,d,e,f =1,2,3,4,5,6
    for i in y :
        In = raw_input()
        if In == "North":
            North()
            z +=a
        elif In == "South":
            South()
            z +=a
        elif In == "East":
            East()
            z +=a
        elif In == "West":
            West()
            z +=a
        elif In == "Right":
            Right()
            z +=a
        elif In == "Left":
            Left()
            z +=a
    print z
    x = int(raw_input())