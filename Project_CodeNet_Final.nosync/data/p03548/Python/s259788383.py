if __name__ == '__main__':
    a = [int(i) for i in input().split()]
    a[0]-=a[2]*2
    print((a[0]+a[2])//(a[1]+a[2]))


