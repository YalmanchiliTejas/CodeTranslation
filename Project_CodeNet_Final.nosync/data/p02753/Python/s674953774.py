if __name__ == '__main__':
    a = input()
    anum = 0

    for i in a:
        if i =="A":
            anum = anum +1

    if anum == 0 or anum ==3:
        print("No")
    else:
        print("Yes")
