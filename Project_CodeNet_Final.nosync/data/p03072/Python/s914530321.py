N = int(input())
li = list(map(int,input().split()))

def main():
    count = 1

    for i in range(len(li)):
        #print(i)
        for j in range(i):
            if li[j] > li[i]:
                #print("li[j]:%d vs li[i]:%d", %(li[j], li[i]))
                break
            elif j == i-1:
            #    print(j)
                count += 1
            #else:
            #    print('j:%d vs i:%d' % (j, i))
            #    print('li[j]:%d vs li[i]:%d' % (li[j], li[i]))
            #    print("error")

    print(count)

if __name__ == '__main__':
    main()
