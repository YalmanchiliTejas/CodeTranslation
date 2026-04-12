#coding:utf-8

a, b = map(int, raw_input().split())

if a < b:
    print("a < b")
elif a > b:
    print("a > b")
elif a == b:
    print("a == b")