import collections
def main():
    x,y,z=map(int, input().split())
    k = y+z+z
    res = 1
    while((k<x)):
        k+=(z+y)
        if(k>x):
            break
        res+=1
    print(res)

if __name__ == '__main__':
    main()
