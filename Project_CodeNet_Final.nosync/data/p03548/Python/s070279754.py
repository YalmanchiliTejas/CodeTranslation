def getNum():
    x,y,z = map(int,input().split())
    return x,y,z

def cal(x,y,z):
    num = int((x-z) / (y+z))
    print(num)

def main():
    x,y,z = getNum()
    cal(x,y,z)

main()
