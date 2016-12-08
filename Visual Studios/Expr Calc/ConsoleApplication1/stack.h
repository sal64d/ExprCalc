#ifndef STACK_H
#define STACK_H

template <class t> class stack;

template <class u>
class node{
public:
	node():next(nullptr){}
	node(u m_var):next(nullptr, var(m_var)){}
private:
	u var;
	node* next; 
	node& operator=(const u& n_var){
		return this->var = n_var;
	}
	friend class stack<u>;
   };

template <class t>
class stack{
private:
    int m_TOP;
    
    node<t>* m_current; 
    node<t>* m_start;

public:
    
    // Overloaded Constructors Methods
    stack(int size = 0){
        m_TOP=-1;
        m_current=m_start=nullptr;
        for(int i(0); i<size; i++)
            push_back();
    }
    stack(int size, const t* array){
        m_TOP=-1;
        m_current=m_start=nullptr;
        for(int i(0); i<size; i++)
            push_back(t[i]);
    }
    stack(int size, const t var){
        m_TOP=-1;
        m_current=m_start=nullptr;
        for(int i(0); i<size; i++)
            push_back(t);
    }
    stack(const stack& obj){
        m_TOP=-1;
        m_current=m_start=nullptr;
        
        for(int i(0); i<=obj.size(); i++){
            push_back(obj.get(i));
        }
    }
    stack(const stack&& obj){
        m_TOP=-1;
        m_current=m_start=nullptr;
        m_start = obj[0];
        m_current = obj[obj.size()];
        obj.m_TOP = -1;
        obj.m_current = obj.m_start= nullptr;
        obj.clear();
    }
    
    // A Destructor Method
    ~stack(){
        clear();
    }
    
    // Normal Methods: 
    void push_back(const t& var){
        m_TOP++;
        if(m_TOP==0){
            m_current = new node<t>;
            m_current->next = nullptr;
            m_current->var = var;
            m_start = m_current;
        } else{
            m_current->next = new node<t>;
            m_current = m_current->next;
            m_current->next = nullptr;
            m_current->var = var;
        }
        
    }
	void push_back(){
        m_TOP++;
        if(m_TOP==0){
            m_current = new node<t>;
            m_current->next = nullptr;
            m_start = m_current;
        } else{
            m_current->next = new node<t>;
            m_current = m_current->next;
            m_current->next = nullptr;
        }
        
    }
    t pop_out(){
        t var;
		if(m_TOP > -1){
			if(m_TOP==0){
				var = m_current->var;
				delete m_current;
				m_current=m_start=nullptr;
			}else if(m_TOP==1){
				var = m_start->next->var;
				delete m_start->next;
				m_start->next=nullptr;
				m_current=m_start;
			} else{
				var = m_current->var;
            
				node<t>* m_del = m_start;
				for(int i(0); i<(m_TOP-1); i++)
					  m_del = m_del->next;
            
				m_current = m_del;
				delete m_del->next;
				m_del->next=nullptr;
			}

			m_TOP--;

		}
        return var;
    }
    
    t get(unsigned int index){
        t var;
        node<t>* m_get = m_start;
        if(index<=m_TOP)
            for(int i(0); i<index; i++)
                m_get = m_get->next;
        var = m_get->var;
        return var;
    }
	t top(){
		if(m_TOP > -1){
		return m_current->var;
		}
    }
    int size(){
        return m_TOP;
    }
    void clear(){
        if(m_TOP!=-1){
            node<t>* m_del = m_start;
            for(int i(0); i<=m_TOP; i++){
                m_current = m_del->next;
                m_del->next = nullptr;
                delete m_del;
                m_del = m_current;
            }
        }
        m_TOP = -1;
        m_current=m_start=nullptr;
    }
    
    // Operator methods
    node<t>* operator[](int index){
        node<t>* m_get = m_start;
        if(index<=m_TOP)
            for(int i(0); i<index; i++)
                m_get = m_get->next;
        return m_get;
    }
    stack& operator=(const stack& obj){
        clear();
        
        for(int i(0); i<=obj.size(); i++){
            push_back(obj.get(i));
        }
        return this;
    }
        

    
};


#endif