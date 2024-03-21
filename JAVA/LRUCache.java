package JAVA;
import java.util.*;
class LRUCache{
    Node head = new Node(0, 0), tail = new Node(0, 0);
    Map<Integer, Node> map=new HashMap<>();
    int capacity;

    public LRUCache(int _capacity){
        capacity=_capacity;
        head.next=tail;
        tail.prev=head;
    }

    public int get(int _key){
        if(map.containsKey(_key)){
            Node node = map.get(_key);
            remove(node);
            insert(node);
            return node.value;
        } else {
            return -1;
        }
    }

    public void put(int _key, int _value){
        if(map.containsKey(_key)){
            remove(map.get(_key));
        }
        if(map.size()==capacity){
            remove(tail.prev);
        }
        insert(new Node(_key, _value));
    }

    private void insert(Node node){
        map.put(node.key, node);
        Node headNext = head.next;
        head.next=node;
        node.prev=head;
        headNext.prev=node;
        node.next=headNext;
    }

    private void remove(Node node){
        map.remove(node.key);
        node.prev.next = node.next;
        node.next.prev=node.prev;
    }

    class Node{
        Node prev, next;
        int key, value;
        Node(int _key, int _value){
            key=_key;
            value=_value;
        }
    }
}