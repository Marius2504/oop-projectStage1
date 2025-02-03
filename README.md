# GSM Service Management System - C++ Project

A comprehensive object-oriented C++ application designed to manage operations for a mobile device repair service. This system handles client devices, employee workflows, inventory management, and service transactions.

## Key Features

### Core Functionality
- **Device Repair Tracking**  
  Manages repair status, parts replacement history, and cost calculations for client devices
- **Employee Management**  
  Tracks technician workloads, salaries, and project assignments
- **Client Profiles**  
  Maintains customer information and repair history with loyalty program support
- **Inventory System**  
  Manages spare parts stock and supplier relationships

### Technical Components

#### Main Classes
1. **ServiceRequest**  
   - Unique repair tracking IDs
   - Device diagnostics and parts replacement tracking
   - Cost calculation algorithms
   - Repair status workflows

2. **Employee**  
   - Technician performance metrics
   - Salary history tracking
   - Project management system
   - Seniority classification (Junior/Senior)

3. **Client** (with **LoyaltyClient** subclass)  
   - Repair history tracking
   - Device ownership records
   - Loyalty discounts and special offers

4. **Warehouse**  
   - Spare parts inventory management
   - Supplier contract tracking
   - Stock value calculations

### OOP Implementation
- **Encapsulation**: Strict access control with private members and public interfaces
- **Inheritance**: Specialized client/employee types through class hierarchies
- **Polymorphism**: Virtual methods for flexible inventory management
- **Operator Overloading**: Streamlined object interactions
- **Memory Management**: Custom destructors and copy constructors

## System Architecture

### Class Relationships
- **Composition**: Service requests contain client/device data
- **Inheritance Hierarchy**:
