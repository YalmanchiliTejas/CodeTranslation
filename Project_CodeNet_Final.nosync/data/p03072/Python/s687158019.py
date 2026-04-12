
def kakaka():
    a = list(map(int, input().split()))
    b = map(int, input().split())
    c = int(input())

def start_process():
    return
def main():
    a = int(input())
    b = list(map(int, input().split()))
    count = 0
    min_data = -1
    for i in range(a):
        if b[i] >= min_data:
            min_data = b[i]
            count += 1
    print(count)




if __name__ == '__main__':
    main()
