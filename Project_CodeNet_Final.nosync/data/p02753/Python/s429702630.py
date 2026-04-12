def main(x):
    a = False
    if 'A' in x:
        if 'B' in x:
            if len(x) == 3:
                a = True
    return a

if __name__ == "__main__":
    x = input()
    v = main(x)
    if v:
        print("Yes")
    else:
        print("No")